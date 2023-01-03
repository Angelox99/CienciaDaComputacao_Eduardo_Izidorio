public class ValorInvalidoException extends RuntimeException{

    ValorInvalidoException(double valor){
        super("\nValor invalido: "+ valor + "\n");
    }

}

