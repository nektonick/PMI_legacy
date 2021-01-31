'''
graph - ассоциативный массив, где вершина - ключ, которому
 соответствует список смежных вершин и стоимости рёбер.

costs - ассоциативный массив, где ключ - вершина, значение - её стоимость.

parents - ассоциативный массив, где ключ - вершина,
 а значение - вершина, из которой в неё пришли.

neighbors - ассоциативный массив с элементами,
соседними вершине node; ключ - смежная вершина, значение -
 стоимость соединяющего ребра.
'''


def Dijkstra():
    #Найти узел с наименьшей стоимостью среди необработанных
    node = find_lower_cost_node(costs)
    while node is not None:#Если обработаны все узлы, цикл завершается
        cost = costs[node]#Получить цену текущей вершины
        #Получить коллекцию соседей вершины в формате "ключ - значение"
        neighbors = graph[node]
        for n in neighbors.keys():#Перебрать всех соседей текущего узла
            new_cost = cost + neighbors[n]
            #Если к соседу можно быстрее добраться через текущий узел...
            if costs[n] > new_cost:
                costs[n] = new_cost
                parents[n] = node
            #обновить стоимость этого узла, текущий узел становится его родителем
        processed.append(node)#узел помечается как обработанный
        node = find_lower_cost_node(costs)

def find_lower_cost_node(costs):
    lowest_cost = float("inf")
    lowest_cost_node = None
    for node in costs:#Перебрать все узлы
        cost = costs[node]
        #Если этот узел с наименьшей стоимость из уже виденных
        #И он ещё не обработан...
        if cost < lowest_cost and node not in processed:
            lowest_cost = cost
            lowest_cost_node = node
        #Он назначается новым узлом с наименьшей стоимостью
    return lowest_cost_node

