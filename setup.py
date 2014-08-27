#!/usr/bin/env python
# -*- coding: utf-8 -*-

from distutils.core import setup, Extension

#package: template_module
#module in package: _template_module
#but!!! with import package we are import all from module _template_module
# (see __init__.py)

module1 = Extension('template_module._template_module',
                    define_macros = [('MAJOR_VERSION', '1'),
                    ('MINOR_VERSION', '0')],
                    include_dirs = ['/usr/local/include'],
                    #libraries = ['tcl83'],
                    library_dirs = ['/usr/local/lib'],
                    sources = ['template.c', 'template_impl.c'])

setup (name = 'TemplateModulePackage',
       version = '1.0',
       description = 'This is a template package',
       author = 'Alexey Kravchenko',
       author_email = 'martin@v.loewis.de',
       url = 'http://google.com',
       packages=['template_module'],
       package_dir={'': 'package'},
       long_description = '''
This is really just a template package.
       ''',
       ext_modules = [module1])

