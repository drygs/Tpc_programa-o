        for (const auto& destaque : meusNumeros) {
            string tabela = (destaque == sorteioAnterior) ? numeroEmVermelho(destaque) : to_string(destaque);
            vetorColorido.push_back(tabela);
        }
