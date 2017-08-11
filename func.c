struct  s_surface* init_s_surface_color(struct s_window* p_window, unsigned int p_w, unsigned int p_h, unsigned int p_x, unsigned int p_y, unsigned short p_color[])
{
        struct s_surface*   ret_s_surface;  /* ptr ret sur la structure init */

        /* creation de la structure */
        ret_s_surface = malloc(sizeof(struct s_surface));

        /* initialisation de la surface sdl de la struct */
        ret_s_surface->sdl_surf = SDL_CreateRGBSurface(SDL_HWSURFACE, p_w, p_h,
                                                        32, 0, 0, 0, 0);

        /* coloration de la surface sdl */
        SDL_FillRect(ret_s_surface->sdl_surf,
                        NULL, SDL_MapRGB(p_window->sdl_win->format,
                        p_color[0], p_color[1], p_color[2]));

        /* definition des coordonnees */
        (*ret_s_surface).coord.x = p_x;
        (*ret_s_surface).coord.y = p_y;

        /* append */
        SDL_BlitSurface(ret_s_surface->sdl_surf,
                        NULL, p_window->sdl_win, &(ret_s_surface->coord));

        return (ret_s_surface);
}
