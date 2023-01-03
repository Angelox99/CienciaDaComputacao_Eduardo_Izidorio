class SistemaInterno
{
    int senha = 0;

    void login(Funcionario funcionario)//ex:1
    {
        funcionario.autentica(...);//Nao compila
    }

    void login(Gerente funcionario)
    {
        funcionario.autentica(...);
    }

    interface Autenticavel
    {
        boolean autentica(int senha);
    }

    bool login(Autenticavel a)//ex:2
    {
        a.autentica(senha);
    }

    void login(Autenticavel a)
    {
        int senha = a;
        ...
    }

    public interface Contrato1
    {
        public void metodoDoContrato1();
    }
}