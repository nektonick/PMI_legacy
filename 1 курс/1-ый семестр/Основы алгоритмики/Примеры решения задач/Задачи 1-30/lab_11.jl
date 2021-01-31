function lab_11(r::Robot)
    for i in (North, East, South, West)
        path = go_to_border_and_return_path!(r, i; go_around_barriers = true)
        putmarker!(r)
        go_by_path!(r, path)
    end
end