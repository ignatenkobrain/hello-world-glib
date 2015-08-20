srcs = [
  'hello-world.c',
  'hello-world.h',
]
shlib = shared_library(
  'hello-world',
  sources : srcs,
  dependencies : gobject,
  install : true,
)
incdir = include_directories('.')
gnome.generate_gir(
  shlib,
  sources : srcs,
  nsversion : '0.1',
  namespace : 'Hello',
  symbol_prefix : 'hello_',
  identifier_prefix : 'Hello',
  includes : ['GObject-2.0'],
  install : true,
)
gi_build_dir = meson.current_build_dir()
