/* hello-world.c
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

#include "hello-world.h"

/**
 * SECTION: hello-world
 * @short_description: hello world
 *
 * #HelloWorld rappresents Hello, World! example.
 */

struct _HelloWorld
{
  GObject parent_instance;

  gchar *msg;
};

G_DEFINE_TYPE (HelloWorld, hello_world, G_TYPE_OBJECT)

enum {
  PROP_0,
  PROP_MESSAGE,
  LAST_PROP
};

static GParamSpec *gParamSpecs [LAST_PROP];

/**
 * hello_world_new:
 * @msg: Message which will used.
 *
 * Allocates a new #HelloWorld.
 *
 * Returns: a #HelloWorld.
 */
HelloWorld *
hello_world_new (const gchar *msg)
{
  return g_object_new (HELLO_TYPE_WORLD,
                       "message", msg,
                       NULL);
}

static void
hello_world_finalize (GObject *object)
{
  HelloWorld *self = (HelloWorld *)object;

  g_free (self->msg);

  G_OBJECT_CLASS (hello_world_parent_class)->finalize (object);
}

static void
hello_world_get_property (GObject    *object,
                          guint       prop_id,
                          GValue     *value,
                          GParamSpec *pspec)
{
  HelloWorld *self = HELLO_WORLD (object);

  switch (prop_id)
    {
    case PROP_MESSAGE:
      g_value_set_string (value, self->msg);
      break;
    default:
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
    }
}

static void
hello_world_set_property (GObject      *object,
                          guint         prop_id,
                          const GValue *value,
                          GParamSpec   *pspec)
{
  HelloWorld *self = HELLO_WORLD (object);

  switch (prop_id)
    {
    case PROP_MESSAGE:
      self->msg = g_strdup (g_value_get_string (value));
      break;
    default:
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
    }
}

static void
hello_world_class_init (HelloWorldClass *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS (klass);

  object_class->finalize = hello_world_finalize;
  object_class->get_property = hello_world_get_property;
  object_class->set_property = hello_world_set_property;

  /**
   * HelloWorld:message:
   *
   * The message which will print.
   */
  gParamSpecs [PROP_MESSAGE] =
    g_param_spec_string ("message",
                         "Message",
                         "The message which will print",
                         NULL,
                         (G_PARAM_READWRITE |
                          G_PARAM_CONSTRUCT_ONLY |
                          G_PARAM_STATIC_STRINGS));
  g_object_class_install_property (object_class, PROP_MESSAGE,
                                   gParamSpecs [PROP_MESSAGE]);
}

static void
hello_world_init (HelloWorld *self)
{
}

/**
 * hello_world_print_message:
 * @self: a #HelloWorld
 *
 * Prints message which set in object
 *
 * Returns: Nothing.
 */
void
hello_world_print_message (HelloWorld *self)
{
  g_print ("Message: %s\n", self->msg);
}
