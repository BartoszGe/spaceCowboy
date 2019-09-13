#!/usr/bin/env python

APPNAME = 'spaceCowboy'
VERSION = '1.0.0'

top = '.'

out = 'build'

def options(opt):
    opt.load('compiler_cxx')

def configure(cfg):
    cfg.load('compiler_cxx')
    cfg.env.LIB_SFML = ['sfml-graphics', 'sfml-system', 'sfml-window']

def build(bld):
    src = bld.path.ant_glob('src/*.cpp')
    bld.program(
        target = 'spaceCowboy',
        source = src,
        includes = ['include', 'include/models'],
        use = ['SFML'],
        cxxflags = ['-std=c++17'])
