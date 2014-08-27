#!/usr/bin/env python
# -*- coding: utf-8 -*-

#defenition of methods:
def get_int():
    pass

def hello(name='Unnamed'):
    pass

#try to import all func from module
try:
    from ._template_module import *
except ImportError:
    # fail :(
    pass

