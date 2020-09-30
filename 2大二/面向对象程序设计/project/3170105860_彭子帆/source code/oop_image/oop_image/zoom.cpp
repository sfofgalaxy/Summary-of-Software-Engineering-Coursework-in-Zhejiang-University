#include "menu.h"
#include "header.h"
#include "factor.h"
void Menu::zoom_funtion()
{
    // to prevent over large/small zoom ratio
    if(zoom_in_or_out > 0)
        zoom_value = (zoom_value < max_zoom) ? (zoom_value + del_zoom) : max_zoom;
    else
        zoom_value = (zoom_value > min_zoom) ? (zoom_value - del_zoom) : min_zoom;
}
