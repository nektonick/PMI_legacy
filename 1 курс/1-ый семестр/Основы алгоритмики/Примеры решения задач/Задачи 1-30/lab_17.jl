function lab_17(r::Robot)
    path = go_to_west_south_corner_and_return_path!(r; go_around_barriers = true)

    x = go_to_border_come_back_and_return_distance!(r, East; go_around_barriers = true)
    marks_to_do = x
    while !isborder(r,Nord) && marks_to_do > 0
        go!(r, East; steps = marks_to_do, go_around_barriers = true, markers = true)
        go!(r, West; steps = marks_to_do, go_around_barriers = true, markers = false)
        move!(r,Nord)
        marks_to_do -= 1
    end
    go!(r, East; steps = marks_to_do, go_around_barriers = true, markers = true)
    go!(r, West; steps = marks_to_do, go_around_barriers = true, markers = false)

    go_to_west_south_corner_and_return_path!(r; go_around_barriers = true)
    go_by_path!(r, path)
end


