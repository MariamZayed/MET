graph = {
    'm': ['t', 'x'],
    't': ['y'],
    'w': ['y', 'z'],
    'x': ['t'],
    'y': ['x'],
    'z': ['z']
}

color    = {}  # WHITE, GRAY, BLACK
parent   = {}
distance = {}
finish   = {}
time     = 0


for node in graph:
    color[node] = "WHITE"
    parent[node] = None

def DFS():
    global time
    time = 0
    for node in graph:
        if color[node] == "WHITE":
            DFS_VISIT(node)

def DFS_VISIT(u):
    global time
    time += 1
    distance[u] = time
    color[u] = "GRAY"

    for v in graph[u]:
        if color[v] == "WHITE":
            parent[v] = u
            DFS_VISIT(v)

    color[u] = "BLACK"
    time += 1
    finish[u] = time




DFS()

print("n\td\tf")
for u in sorted(graph):
    print(f"{u}\t{distance[u]}\t{finish[u]}")
