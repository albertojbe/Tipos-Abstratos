module Main where

data Biblioteca = Biblioteca {
    tituloLivro :: String,
    autorLivro :: String,
    anoLivro :: Int,
    numeroCopias :: Int
}

inicializar :: String -> String -> Int -> Int -> Biblioteca
inicializar titulo autor ano copias = Biblioteca titulo autor ano copias

emprestarCopias :: Biblioteca -> Biblioteca
emprestarCopias livro = livro { numeroCopias = (numeroCopias livro) - 1 }

devolverCopias :: Biblioteca -> Biblioteca
devolverCopias livro = livro { numeroCopias = (numeroCopias livro) + 1 }

verificarCopias :: Biblioteca -> IO ()
verificarCopias livro =
    if numeroCopias livro > 0
        then putStrLn $ "O número de cópias é: " ++ show (numeroCopias livro)
        else putStrLn "Não há cópias disponíveis."

imprimirDetalhes :: Biblioteca -> IO ()
imprimirDetalhes livro = do
    imprimir "Título: %s\n" (tituloLivro livro)
    imprimir "Autor: %s\n" (autorLivro livro)
    imprimir "Ano de lançamento: %d\n" (anoLivro livro)
    imprimir "Número de cópias: %d\n" (numeroCopias livro)

imprimir :: String -> ShowS
imprimir formato args = printf formato args

main :: IO ()
main = do
    let livroUm = inicializar "O Festim dos Corvos" "George Martin" 2005 5
    imprimirDetalhes livroUm
