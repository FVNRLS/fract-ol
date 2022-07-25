void	conv_to_complex_plain_coord(t_fr *fr, double *x, double *y)
{
    *x = fr->view.re_min + ((*x / WINSIZE) * fr->view.scope);
    *y = fr->view.im_max - ((*y / WINSIZE) * fr->view.scope);
}

void	zoom(int x, int y, t_fr *fr, double zoom)
{
    double	re_pos;
    double	im_pos;

    re_pos = fr->view.re_min + (((double) x / WINSIZE) * fr->view.scope);
    im_pos = fr->view.im_max - (((double) y / WINSIZE) * fr->view.scope);
    if ((zoom > 1 && fr->view.scope > 10 && fr->calc_fractal != &calc_newton)
        || (zoom < 1 && fr->view.scope < 0.0000000000001))
    {
        if (!fr->view.zoom_max_reached)
        {
            ft_printf("\tZoom max is reached! Press space bar to reset\n");
            fr->view.zoom_max_reached = 1;
        }
        return ;
    }
    fr->view.scope = zoom * fr->view.scope;
    fr->view.re_min = re_pos - (((double) x / WINSIZE) * fr->view.scope);
    fr->view.im_max = im_pos + (((double) y / WINSIZE) * fr->view.scope);
    make_image(fr);
}