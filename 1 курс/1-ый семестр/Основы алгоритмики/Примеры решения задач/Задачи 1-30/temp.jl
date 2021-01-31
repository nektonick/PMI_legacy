#СТОРОНЫ света

""" Север """
North = Nord



""" Юг """
South = Sud


#Запад - уже определён как West


""" Восток """
East = Ost


line_side = (Nord, West) ; ortogonal_line_side = (Nord, East) ; num_passes = 0; num_start_passes = 0


include("libs/HorizonSideRobots.jl")
using .HorizonSideRobots

include("libs/roblib.jl")


using Plots

include("lab_29.jl")