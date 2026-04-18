graph = {
    'u': ['v', 'x'],
    'v': ['y'],
    'w': ['y', 'z'],
    'x': ['v'],
    'y': ['x'],
    'z': ['z']
}

color = {}  # WHITE, GRAY, BLACK
pi    = {}
d     = {}
f     = {}
time  = 0

WHITE, GRAY, BLACK = 0, 1, 2


for u in graph:
    color[u] = WHITE
    pi[u] = None

def DFS():
    global time
    time = 0
    for u in graph:
        if color[u] == WHITE:
            DFS_VISIT(u)

def DFS_VISIT(u):
    global time
    time += 1
    d[u] = time
    color[u] = GRAY

    for v in graph[u]:
        if color[v] == WHITE:
            pi[v] = u
            DFS_VISIT(v)

    color[u] = BLACK
    time += 1
    f[u] = time




DFS()

print("ta\td\tf")
for u in sorted(graph):
    print(f"{u}\t\t{d[u]}\t{f[u]}")
