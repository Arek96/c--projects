#pragma once

struct point_t
{
    double x, y, z;
};

struct list_el 
{
    point_t p;
    list_el *next;
    list_el(const point_t &p);
};

enum result_en {
    res_ok,
    res_out_of_range,
    res_error,
};
