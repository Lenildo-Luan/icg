#ifndef MYGL_H
#define MYGL_H

#include "core.h"
#include "frame_buffer.h"
#include "pixel.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Declaração da função que chamará as funções implementadas pelo aluno
void MyGlDraw(void);

//
// >>> Declare aqui as funções que você implementar <<<

struct pixel
{
    int x;
    int y;
    int red;
    int green;
    int blue;
    int alpha;
};

void PutPixel(struct pixel p0);
void DrawnLine(struct pixel p0, struct pixel p1);
void DrawnLineInverted(struct pixel p0, struct pixel p1);
//

#endif // MYGL_H
