public class TestaDeposita{
    public static void main(String[] args) throws ValorInvalidoException{

        Conta cp= new ContaPoupança();

        try{
        cp.Deposita(-100);
        } catch(ValorInvalidoException exception){
            System.out.println(exception.getMessage());
        }

        /* Questão 7 - Como a classe passa a ser checked, somos obrigados a trata-la, com try-catch ou throws. 
        No caso das unchecked exceptions se torna opcional e você trata apenas se quiser. */
    }
}