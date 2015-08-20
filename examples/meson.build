hello = executable(
  'hello',
  sources : 'hello.c',
  link_with : shlib,
  dependencies : gobject,
  include_directories : incdir,
)
test('hello/c', hello)
test('hello/py',
     find_program('hello.py'),
     env : [
       'GI_TYPELIB_PATH=@0@'.format(gi_build_dir),
       'LD_LIBRARY_PATH=@0@'.format(gi_build_dir),
     ]
)
