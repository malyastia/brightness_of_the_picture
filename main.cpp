#include <iostream>

#include <QColor>
#include <QImageWriter>
#include <QFileDialog>



// brightness coefficient 0-1
#define  K_OF_BRIGHTNESS 1


//filepath of image
QString image_from ("img\\in.jpg");

//file save_path
QString image_save ("img\\out.jpg");


int min (int a, int b) {
  return !(b<a)?a:b;     // or: return !comp(b,a)?a:b; for version (2)
}

int main(int argc, char *argv[])
{


    QImage img;
    if( !img.load(image_from) )
    {
        std::cout << "Not correct filepath or not exist" <<std::endl;
        return 0;
    }

    int r, g, b;

    for (int i = 0; i < img.width(); ++i)
    {
        for (int j = 0; j < img.height(); ++j)
        {

            QRgb c = QRgb(img.pixel(i,j));


            QColor col(c);

            col.getRgb(&r,&g,&b);

            double tmp_r, tmp_g, tmp_b;
            tmp_r = (255 - r) * K_OF_BRIGHTNESS + r;
            tmp_g = (255 - g) * K_OF_BRIGHTNESS + g;
            tmp_b = (255 - b) * K_OF_BRIGHTNESS + b;

            if(tmp_r>255)
                tmp_r=255;
            if(tmp_g>255)
                tmp_g=255;
            if(tmp_b>255)
                tmp_b=255;
            img.setPixel(i, j, qRgb( (int)tmp_r, (int)tmp_g, (int)tmp_b));
        }
    }

    if (img.save(image_save))
    {
        std::cout << "SUCCESS " <<std::endl;
    }
    else
    {
        std::cout << "Not save" <<std::endl;
    }

    return 0;
}
