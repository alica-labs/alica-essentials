project('id_manager', 'cpp',
  version : '0.0.0',
  license : 'MPL-2.0')

project_description = 'A library to manage arbitrary kind of ids within your application.'

uuid = dependency('uuid')

project_headers = [
  'include/IdentifierConstPtr.h',  
  'include/Identifier.h',  
  'include/IDManager.h',
  'include/WildcardID.h'
]

project_source_files = [
  'src/Identifier.cpp',
  'src/IDManager.cpp',
  'src/WildcardID.cpp'
]

project_test_files = [
  'tests/src/IDTests.cpp'
]

build_args = [
]


# ===================================================================

# ======
# Target
# ======

public_headers = include_directories('include')

build_args += [
  '-DPROJECT_NAME=' + meson.project_name(),
  '-DPROJECT_VERSION=' + meson.project_version(),
]

project_target = library(
  meson.project_name(),
  project_source_files,
  c_args : build_args,
  include_directories : public_headers,
  dependencies : uuid
)


# =======
# Project
# =======

# Make this library usable as a Meson subproject.
project_dep = declare_dependency(
  include_directories: public_headers,
  link_with : project_target,
  version : meson.project_version(),
)
meson.override_dependency(meson.project_name(), project_dep)

# ==========
# Unit Tests
# ==========

subdir('tests')
