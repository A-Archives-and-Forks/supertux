//  SuperTux
//  Copyright (C) 2006 Matthias Braun <matze@braunis.de>
//
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>.

#ifndef HEADER_SUPERTUX_VIDEO_SDL_RENDERER_HPP
#define HEADER_SUPERTUX_VIDEO_SDL_RENDERER_HPP

#include <SDL.h>

#include "math/size.hpp"
#include "video/renderer.hpp"

class SDLRenderer : public Renderer
{
public:
  SDLRenderer(SDL_Renderer* renderer);
  ~SDLRenderer();

  void start_draw() override;
  void end_draw() override;

  void draw_surface(const DrawingRequest& request) override;
  void draw_surface_part(const DrawingRequest& request) override;
  void draw_gradient(const DrawingRequest& request) override;
  void draw_filled_rect(const DrawingRequest& request) override;
  void draw_inverse_ellipse(const DrawingRequest& request) override;
  void draw_line(const DrawingRequest& request) override;
  void draw_triangle(const DrawingRequest& request) override;
  void clear();

  Vector to_logical(int physical_x, int physical_y) const override;

  void flip();
  SDL_Renderer* get_sdl_renderer() const { return m_renderer; };

  void set_viewport(const SDL_Rect& viewport, const Vector& scale);
  SDL_Rect get_viewport() const { return m_viewport; }

private:
  SDL_Renderer* m_renderer;
  SDL_Rect m_viewport;
  Vector m_scale;

private:
  SDLRenderer(const SDLRenderer&);
  SDLRenderer& operator=(const SDLRenderer&);
};

#endif

/* EOF */
