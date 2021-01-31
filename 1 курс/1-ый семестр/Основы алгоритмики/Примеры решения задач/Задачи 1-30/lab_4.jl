function lab_4(r::Robot)
    path = go_to_west_south_corner_and_return_path!(r; go_around_barriers = false)

    x = go_to_border_come_back_and_return_distance!(r, East; go_around_barriers = false)
    marks_to_do = x
    while !isborder(r,Nord) && marks_to_do > 0
        go!(r, East; steps = marks_to_do, go_around_barriers = false, markers = true)
        go!(r, West; steps = marks_to_do, go_around_barriers = false, markers = false)
        move!(r,Nord)
        marks_to_do -= 1
    end
    go!(r, East; steps = marks_to_do, go_around_barriers = false, markers = true)
    go!(r, West; steps = marks_to_do, go_around_barriers = false, markers = false)

    go_to_west_south_corner_and_return_path!(r; go_around_barriers = false)
    go_by_path!(r, path)
end

