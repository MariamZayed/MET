from collections import deque

# Graph
Graph = {
    's': ['w', 'r'],
    'w': ['t', 'x'],
    'r': ['v'],
    'v': [],
    't': ['u'],
    'x': ['y'],
    'u': [],
    'y': []
}

def BFS(Graph, start_node):
    color = {}
    distance = {}
    pi = {}

    # Initialize all vertices
    for node in Graph:
        color[node] = "WHITE"
        distance[node] = float('inf') # Infinitely large value.
        pi[node] = None 

    # Initialize source vertex
    color[start_node] = "GRAY"
    distance[start_node] = 0
    pi[start_node] = None

    queue  = deque() # Intializes an empty queue
    queue.append(start_node)

    while queue: # Continue until it is empty
        u = queue.popleft() # u is an one item not list 

        for v in Graph[u]:
            if color[v] == "WHITE":
                color[v] = "GRAY"
                distance[v] = distance[u] + 1
                pi[v] = u
                queue.append(v)

        color[u] = "BLACK" 
        print(f"Visited: {u}, Distance: {distance[u]}, Parent: {pi[u]}")

    return distance, pi


# Run BFS
distance, pi = BFS(Graph, 's')

print(f"\nFinal Results:")
for node in Graph:
    print(f"{node}: Distance = {distance[node]}, Parent = {pi[node]}")

# Visited: s, Distance: 0, Parent: None
# Visited: w, Distance: 1, Parent: s
# Visited: r, Distance: 1, Parent: s
# Visited: t, Distance: 2, Parent: w
# Visited: x, Distance: 2, Parent: w
# Visited: v, Distance: 2, Parent: r
# Visited: u, Distance: 3, Parent: t
# Visited: y, Distance: 3, Parent: x

# Final Results:
# s: Distance = 0, Parent = None
# w: Distance = 1, Parent = s
# r: Distance = 1, Parent = s
# v: Distance = 2, Parent = r
# t: Distance = 2, Parent = w
# x: Distance = 2, Parent = w
# u: Distance = 3, Parent = t
# y: Distance = 3, Parent = x