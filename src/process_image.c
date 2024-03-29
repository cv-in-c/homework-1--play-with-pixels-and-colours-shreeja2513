#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include "image.h"

float get_pixel(image im, int x, int y, int c)
{
    // TODO Fill this in
    x = fminf(fmaxf(x, 0), im.w - 1);
    y = fminf(fmaxf(y, 0), im.h - 1);
    c = fminf(fmaxf(c, 0), im.c - 1);
    int index = c * im.w * im.h + y * im.w + x;
    return im.data[index];
}

void set_pixel(image im, int x, int y, int c, float v)
{
    // TODO Fill this in
    if (x >= 0 && x < im.w && y >= 0 && y < im.h && c >= 0 && c < im.c)
    {
        
        int index = c * im.w * im.h + y * im.w + x;
        
        
        im.data[index] = v;
    }

    
}

image copy_image(image im)
{
    image copy = make_image(im.w, im.h, im.c);
    // TODO Fill this in
    memcpy(copy.data,im.data,im.w*im.h*im.c*sizeof(float));
    return copy;
}

image rgb_to_grayscale(image im)
{
    assert(im.c == 3);
    image gray = make_image(im.w, im.h, 1);
    // TODO Fill this in
    im = load_image("data/colorbar.png");
   graybar = rgb_to_grayscale(im);
     save_image(graybar, "graybar"); 
    return gray;
}

void shift_image(image im, int c, float v)
{
    // TODO Fill this in
    for (int y = 0; y < im.h; y++)
    {
        for (int x = 0; x < im.w; x++)
        {
            float pixel = get_pixel(im, x, y, c);
            set_pixel(im, x, y, c, pixel + v);
        }
    }
}

void clamp_image(image im)
{
    // TODO Fill this in
}


// These might be handy
float three_way_max(float a, float b, float c)
{
    return (a > b) ? ( (a > c) ? a : c) : ( (b > c) ? b : c) ;
}

float three_way_min(float a, float b, float c)
{
    return (a < b) ? ( (a < c) ? a : c) : ( (b < c) ? b : c) ;
}

void rgb_to_hsv(image im)
{
    // TODO Fill this in
}

void hsv_to_rgb(image im)
{
    // TODO Fill this in
}
