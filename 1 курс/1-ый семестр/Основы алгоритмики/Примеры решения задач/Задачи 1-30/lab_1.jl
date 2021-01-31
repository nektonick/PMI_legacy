function lab_1(r::Robot)   
    for i ∈ (North, South, West, East)
        go_to_border_come_back_and_return_distance!(r, i; markers = true)
    end
    putmarker!(r)
end