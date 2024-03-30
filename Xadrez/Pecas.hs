module Main where

import Text.Printf

data Pecas = Pecas {
    tipo :: String,
    cor :: String,
    linha :: Int,
    coluna :: Int
}

inicializarPecas :: String -> String -> Int -> Int -> Pecas
inicializarPecas tipo cor linha coluna = Pecas tipo cor linha coluna

imprimirInformacoes :: Pecas -> IO ()
imprimirInformacoes peca = do
    imprimir "Tipo da peça: " (tipo peca)
    imprimir "Cor da peça: " (cor peca)
    printf "Posição: %d%d\n" (linha peca) (coluna peca)

imprimir :: String -> String -> IO ()
imprimir texto arg = putStrLn (texto ++ arg)

data Peao = Peao {
    super :: Pecas
}

inicializarPeao :: String -> String -> Int -> Int -> Peao
inicializarPeao tipo cor linha coluna = Peao (inicializarPecas tipo cor linha coluna)

verificarMovimento :: Peao -> Int -> Bool
verificarMovimento peao novaLinha
    | (linha (super peao) == 2 || linha (super peao) == 7) && (novaLinha == 4 || novaLinha == 5) = True
    | abs (novaLinha - linha (super peao)) == 1 = True
    | otherwise = False

movimentarPeao :: Peao -> Int -> IO ()
movimentarPeao peao novaLinha =
    if verificarMovimento peao novaLinha
        then do
            let novaPeca = (super peao) { linha = novaLinha }
            imprimir "Movimento Realizado"
            imprimirInformacoes novaPeca
        else imprimir "Movimento Inválido"

capturarPeca :: Peao -> Int -> Int -> String -> IO ()
capturarPeca peao colunaCapturar linhaCapturar pecaCapturada =
    if (abs (coluna (super peao) - colunaCapturar) == 1 || abs (linha (super peao) - linhaCapturar) == 1)
        then printf "A peça %s foi capturada com sucesso na linha %d coluna %d!\n" pecaCapturada linhaCapturar colunaCapturar
        else imprimir "Movimento inválido!"
