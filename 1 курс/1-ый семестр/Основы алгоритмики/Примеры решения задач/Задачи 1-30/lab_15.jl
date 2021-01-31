function lab_15(r::Robot)
    path = go_to_west_south_corner_and_return_path!(r; go_around_barriers = true)

    for i ∈ (North, East, South, West)
        go_to_border_and_return_path!(r, i; markers = true)
    end
    go_by_path!(r, path)
    
end