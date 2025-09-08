uto [v,id]: g[u]) {
            if (v!=parent[u] && v!=heavy[u]) decompose(v,v);
        }