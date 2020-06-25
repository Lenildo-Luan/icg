#include "mygl.h"

//
// >>> Defina aqui as funções que você implementar <<<
void PutPixel(struct pixel p0)
{
    fb_ptr[4 * p0.x + 4 * p0.y * IMAGE_WIDTH + 0] = p0.red;
    fb_ptr[4 * p0.x + 4 * p0.y * IMAGE_WIDTH + 1] = p0.green;
    fb_ptr[4 * p0.x + 4 * p0.y * IMAGE_WIDTH + 2] = p0.blue;
    fb_ptr[4 * p0.x + 4 * p0.y * IMAGE_WIDTH + 3] = p0.alpha;
}

void DrawnLine(struct pixel p0, struct pixel p1)
{
    int inc_x = 1;
    if (p0.x > p1.x)
    {
        struct pixel aux;
        aux = p0;
        p0 = p1;
        p1 = aux;
    }
    else if (p0.x == p1.x)
    {
        inc_x = 0;
    }
    int inc_y = (p0.y > p1.y) ? -1 : 1;

    int dx = p1.x - p0.x;
    int dy = (p1.y - p0.y) * inc_y;
    int d = 2 * dy - dx;
    int inc_e = 2 * dy;
    int inc_ne = 2 * (dy - dx);
    int inc = dx + (dy * (1 - inc_x));

    printf("%d \n", inc);

    int dRed = p1.red - p0.red, dGreen = p1.green - p0.green;
    int dBlue = p1.blue - p0.blue, dAlpha = p1.alpha - p0.alpha;
    int inc_red = (dRed < inc && dRed > 0) ? 1 : dRed / inc;
    int inc_green = (dGreen < inc && dGreen > 0) ? 1 : dGreen / inc;
    int inc_blue = (dBlue < inc && dBlue > 0) ? 1 : dBlue / inc;
    int inc_alpha = (dAlpha < inc && dAlpha > 0) ? 1 : dAlpha / inc;

    PutPixel(p0);

    for (int i = 0; i < inc; i++)
    {

        p0.x += inc_x;

        if (d <= 0)
        {
            d += inc_e;

            p0.red += inc_red;
            p0.green += inc_green;
            p0.blue += inc_blue;
            p0.alpha += inc_alpha;
        }
        else
        {
            d += inc_ne;
            p0.y += inc_y;

            p0.red += inc_red;
            p0.green += inc_green;
            p0.blue += inc_blue;
            p0.alpha += inc_alpha;
        }

        PutPixel(p0);
    }
}

void DrawnLineInverted(struct pixel p0, struct pixel p1)
{
    int inc_x = 1;
    int dRed = p1.red - p0.red, dGreen = p1.green - p0.green;
    int dBlue = p1.blue - p0.blue, dAlpha = p1.alpha - p0.alpha;

    if (p0.x > p1.x)
    {
        struct pixel aux;
        aux = p0;
        p0 = p1;
        p1 = aux;
    }
    else if (p0.x == p1.x)
    {
        inc_x = 0;
    }

    int inc_y = (p0.y > p1.y) ? -1 : 1;

    int dx = p1.x - p0.x;
    int dy = (p1.y - p0.y) * inc_y;

    int d = 2 * dx - dy;
    int inc_e = 2 * dx;
    int inc_ne = 2 * (dx - dy);

    int inc = dy;
    int inc_red = dRed / inc, inc_green = dGreen / inc;
    int inc_blue = dBlue / inc, inc_alpha = dAlpha / inc;

    PutPixel(p0);

    for (int i = 0; i < inc; i++)
    {

        p0.y += inc_y;
        if (d <= 0)
        {
            d += inc_e;

            p0.red += inc_red;
            p0.green += inc_green;
            p0.blue += inc_blue;
            p0.alpha += inc_alpha;
        }
        else
        {
            d += inc_ne;
            p0.x += inc_x;

            p0.red += inc_red;
            p0.green += inc_green;
            p0.blue += inc_blue;
            p0.alpha += inc_alpha;
        }

        PutPixel(p0);
    }
}

void DrawnTriangle(struct pixel p0, struct pixel p1, struct pixel p2)
{
    if (abs(p1.y - p0.y) > abs(p1.x - p0.x))
    {
        DrawnLineInverted(p0, p1);
    }
    else
    {
        DrawnLine(p0, p1);
    }

    if (abs(p2.y - p1.y) > abs(p2.x - p1.x))
    {
        DrawnLineInverted(p1, p2);
    }
    else
    {
        DrawnLine(p1, p2);
    }

    if (abs(p0.y - p2.y) > abs(p0.x - p2.x))
    {
        DrawnLineInverted(p2, p0);
    }
    else
    {
        DrawnLine(p2, p0);
    }
}

void GetColor() {}

//

// Definição da função que chamará as funções implementadas pelo aluno
void MyGlDraw(void)
{
    struct pixel p0, p1, p2;

    p0.x = 127;
    p0.y = 255;
    p0.red = 255;
    p0.green = 0;
    p0.blue = 0;
    p0.alpha = 255;

    p1.x = 255;
    p1.y = 300;
    p1.red = 0;
    p1.green = 255;
    p1.blue = 0;
    p1.alpha = 255;

    p2.x = 383;
    p2.y = 127;
    p2.red = 0;
    p2.green = 0;
    p2.blue = 255;
    p2.alpha = 255;

    // >>> Chame aqui as funções que você implementou <<<
    DrawnTriangle(p0, p1, p2);

    PutPixel(p0);
    PutPixel(p1);
    PutPixel(p2);
}
