# Задачи по алгоритмике
## Запуск программ
Выполняем в терминале следующие команды находясь в папке `Задачи 1-18 на русском`: 
```julia
> julia
julia> include("src/HorizonSideRobots.jl")
julia> using .HorizonSideRobots
julia> include("src/roblib.jl")
julia> r = Robot(animate=true)
julia> include("lab_name.jl")
```
где `"lab_name.jl"` - название файла с заданием.
После этого можно выполнять основную функцию файла (для разных файлов она разная).