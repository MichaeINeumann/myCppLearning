#pragma once

#include <graaflib/graph.h>
#include <graaflib/algorithm/shortest_path/dijkstra_shortest_path.h>
#include <vector>
#include <optional>

class GraphTool {
public:
    GraphTool();

    // Gibt Pfad von start zu ziel zurück
    std::optional<std::vector<graaf::vertex_id_t>> findeKuerzestenPfad(graaf::vertex_id_t start, graaf::vertex_id_t ziel);

private:
    graaf::undirected_graph<int, float> graph_;
};
