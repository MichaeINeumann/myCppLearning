#include "GraphTool.hpp"

GraphTool::GraphTool() {
    // Knoten hinzufügen
    auto id0 = graph_.add_vertex(1); // ID 0
    auto id1 = graph_.add_vertex(2); // ID 1
    auto id2 = graph_.add_vertex(3); // ID 2

    // Kanten: 0 --1.0--> 1, 1 --1.0--> 2
    graph_.add_edge(0, 1, 1.0f);
    graph_.add_edge(1, 2, 1.0f);
}

std::optional<std::vector<graaf::vertex_id_t>> GraphTool::findeKuerzestenPfad(
    graaf::vertex_id_t start, graaf::vertex_id_t ziel) {
    try {
        auto result = graaf::algorithm::dijkstra_shortest_path(graph_, start, ziel);
        if (result.has_value()) {
            // Konvertiere von std::list zu std::vector
            return std::vector<graaf::vertex_id_t>(
                result->vertices.begin(),
                result->vertices.end());
        }
        return std::nullopt;
    } catch (...) {
        return std::nullopt;
    }
}

