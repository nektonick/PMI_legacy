function lab_3(r::Robot)
    path = go_to_west_south_corner_and_return_path!(r)

    side = East
    while !isborder(r,North)
        go_to_border_and_return_path!(r, side; markers = true)
        side = inverse_side(side)
        go!(r, North)
    end

    go_to_border_and_return_path!(r, side; markers = true)

    go_to_west_south_corner_and_return_path!(r)
    go_by_path!(r, path)
end
