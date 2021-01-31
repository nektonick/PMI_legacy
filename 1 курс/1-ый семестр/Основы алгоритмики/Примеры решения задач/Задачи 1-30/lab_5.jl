function lab_5(r::Robot)

    putmarker!(r)

    path = go_to_west_south_corner_and_return_path!(r; go_around_barriers = true)

    for side in (North, East, South, West)
        go_to_border_and_return_path!(r, side)
        putmarker!(r)
    end

    go_by_path!(r, path)
end
