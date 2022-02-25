gtest_dep = dependency('gtest', main : true, required : true)

testexe = executable('IDTests', 'src/IDTests.cpp',
                     include_directories : public_headers,
                     link_with : project_target,
                     dependencies : gtest_dep)
test('IDTests', testexe)