class ContaCorrente extends Conta{

    public void Atualiza(double taxa) {
        this.saldo += this.saldo*(taxa*2);
    }

    public void Deposita(double valor) throws ValorInvalidoException{
        if (valor<0){
            throw new ValorInvalidoException(valor);
        }else{
        this.saldo += valor - 0.10;
        }
    }




}