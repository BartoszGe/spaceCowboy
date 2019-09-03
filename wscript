#!/usr/bin/env python

APPNAME = 'spaceCowboy'
VERSION = '0.0.1'

top = '.'

out = 'build'

def options(opt):
    opt.load('compiler_cxx')

def configure(cfg):
    cfg.load('compiler_cxx')
    cfg.env.LIB_SFML = ['sfml-graphics', 'sfml-system', 'sfml-window']

def build(bld):
    src = bld.path.ant_glob('src/*.cpp')
    inc = ['include']
    bld.program(
        target = 'spaceCowboy',
        source = src,
        include = inc,
        use = 'SFML')
