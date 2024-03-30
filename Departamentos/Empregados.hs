data Empregados = Empregados {
    nome :: String,
    id :: Int,
    cargo :: String,
    salario :: Float,
    departamento :: Maybe Departamento
} deriving (Show)

data Departamento = Departamento {
    nomeD :: String,
    idD :: Int,
    localizacao :: String,
    empregados :: [Empregados]
} deriving (Show)

atualizarDados :: Empregados -> String -> String -> Float -> Empregados
atualizarDados emp novoNome novoCargo novoSalario = emp { nome = novoNome, cargo = novoCargo, salario = novoSalario }

transferencia :: Departamento -> Empregados -> Empregados
transferencia depto emp = emp { departamento = Just depto }

imprimirDados :: Empregados -> IO ()
imprimirDados emp = do
    putStrLn $ "Nome: " ++ nome emp
    putStrLn $ "ID: " ++ show (id emp)
    putStrLn $ "Cargo: " ++ cargo emp
    putStrLn $ "Salário: " ++ show (salario emp) ++ "\n"

imprimirEmpregados :: Departamento -> IO ()
imprimirEmpregados depto = do
    putStrLn "Lista de Empregados:\n"
    mapM_ imprimirDados (empregados depto)

informacoesDepartamento :: Departamento -> IO ()
informacoesDepartamento depto = do
    putStrLn $ "Nome: " ++ nomeD depto
    putStrLn $ "ID: " ++ show (idD depto)
    putStrLn $ "Localizacao: " ++ localizacao depto

main :: IO ()
main = do
    let alberto = Empregados "Alberto" 18 "Atendente" 1300.00 Nothing
        carlos = Empregados "Carlos" 18 "Atendente" 1300.00 Nothing
        recepcao = Departamento "Recepção" 1 "Entrada" [alberto, carlos]

    let albertoTransferido = transferencia recepcao alberto
        carlosTransferido = transferencia recepcao carlos

    putStrLn "Empregados na Recepção:"
    imprimirEmpregados recepcao

    putStrLn "\nInformações do Departamento:"
    informacoesDepartamento recepcao
