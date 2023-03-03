int binary_tree_is_heap(const binary_tree_t *tree)
{
   if(tree==NULL) 
      return(0);
   int node_count = countNodes(tree);
   int index = 0;

   if(isComplete(tree,index,node_count)&&isHeapUtil(tree))
      return(1);
   else
      return(0);
}