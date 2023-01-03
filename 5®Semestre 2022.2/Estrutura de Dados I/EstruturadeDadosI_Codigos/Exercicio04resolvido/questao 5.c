/* --------------------------------------------------------
* Exercício: – Questão 05
* Autor: Eduardo Henrique de Almeida Izidorio
* Matrícula: 2020000315
----------------------------------------------------------*/

void ConcatenacaoLista(DoublyNode **p0, DoublyNode **p1)
{
  DoublyNode *p3 = NULL; // Nó auxiliar
  if (p0 == NULL && p1 == NULL)
  {
    printf("\nERRO");
  }
  else
  {
    p3 = (DoublyNode *)malloc(sizeof(DoublyNode));

    if (p3 == NULL)
    {
      printf("\nERRO");
    }
    else
    {
      p3 = *p0;

      while (p3->next != NULL)
      {
        p3 = p3->next;
      }

      p3->next = (*p1);
      (*p1)->prev = p3;
    }
  }
}
  