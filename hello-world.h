/* hello-world.h
 *
 * Copyright (C) 2015 Igor Gnatenko <i.gnatenko.brain@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef HELLO_WORLD_H
#define HELLO_WORLD_H

#include <glib-object.h>

G_BEGIN_DECLS

#define HELLO_TYPE_WORLD (hello_world_get_type())

G_DECLARE_FINAL_TYPE (HelloWorld, hello_world, HELLO, WORLD, GObject)

HelloWorld *hello_world_new    (const gchar *msg);
void hello_world_print_message (HelloWorld  *self);

G_END_DECLS

#endif /* HELLO_WORLD_H */
