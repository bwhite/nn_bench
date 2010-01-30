import distutils.sysconfig
env = Environment()

env.Replace(CXX = 'g++')
env.Append(CCFLAGS =  '-O3')
env.Append(CCFLAGS =  '-pedantic -ansi -Wall')
env.Append(CPPPATH = ['/usr/include/python2.6/'])
env.Append(CPPPATH= [distutils.sysconfig.get_python_inc()])
env.Append(SWIGFLAGS = '-python')
env.Append(SWIGFLAGS = '-c++')
env.Append(SWIGFLAGS = '-Wall')
env.Append(SWIGFLAGS = '-DOBFUSOFF')
env.Append(SWIGFLAGS = '-shadow')


env.Program('bench',['bench.c', 'nn.c'], CCFLAGS = '-O3 -pg', LINKFLAGS = '-pg')
env.SharedLibrary('nn', ['nn.c'])
env.SharedLibrary('_NearestNeighbor',['NearestNeighbor.cpp', 'NearestNeighbor.i'], SHLIBPREFIX = '_')
Default('.')