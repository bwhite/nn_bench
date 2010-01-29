import distutils.sysconfig
env = Environment()

env.Replace(CXX = 'g++')
env.Append(CCFLAGS =  '-O3')
env.Append(CCFLAGS =  '-pedantic -ansi -Wall')

env.Program('bench',['bench.c', 'nn.c'], CCFLAGS = '-O3 -pg', LINKFLAGS = '-pg')
env.SharedLibrary('nn', ['nn.c'])
Default('.')