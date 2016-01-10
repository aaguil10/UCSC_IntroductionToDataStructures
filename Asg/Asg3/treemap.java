

import java.io.*;
import static java.lang.System.*;

class treemap <key_t extends Comparable<key_t>, value_t> {

   private class bstree {
      key_t key;
      value_t value;
      bstree left;
      bstree right;
   }
   private bstree root = null;
 
boolean wentright = false;
bstree parent = null;
  public value_t putRecur(bstree curr,key_t key,value_t value){
      if(curr == null && parent == null){
         bstree leaf = new bstree();
         leaf.key = key;
         leaf.value = value;
         root = leaf;
         return leaf.value;
      }
      if(curr == null && parent != null){
         bstree leaf = new bstree();
         leaf.key = key;
         leaf.value = value;
         if(wentright == false){
            parent.left = leaf;
         }
         if(wentright == true){
            parent.right = leaf;
         }
       return leaf.value;
      }
      if(curr.key.equals(key)){
         curr.value = value;
         return curr.value;
      }
      parent = curr;
      wentright = false;
      putRecur(curr.left,key,value);
      wentright = true;
      putRecur(curr.right,key,value);
      return null;
    
   }


   public value_t put (key_t key, value_t value) {
      int cmp = root.key.compareTo (key);
      return putRecur(root,key,value);

//      throw new UnsupportedOperationException ();

   }

   public value_t getRecur(bstree rooter,key_t key){
      if(rooter == null){
         return null;
     }
      getRecur(rooter.left,key);
      if(rooter.key.equals(key)){
        return rooter.value;
      }
      getRecur(rooter.right,key);
      return null;
   }



   public value_t get (key_t key) {
      return getRecur(root,key);
//      throw new UnsupportedOperationException ();
   }

   public value_t remove (key_t key) {
      throw new UnsupportedOperationException ();
   }

   public void visit_all (visitor <key_t, value_t> visitor_fn) {
      visit_all_inorder (root, visitor_fn);
   }

   private void visit_all_inorder (bstree tree,visitor <key_t, value_t> visitor_fn) {
      if(tree == null){
         return;
     }
      visit_all_inorder (tree.left,visitor_fn);
      visitor_fn.visit (tree.key, tree.value);
      visit_all_inorder (tree.right,visitor_fn);
//      throw new UnsupportedOperationException ();
   }

   public void debug_dump () {
      debug_dump_inorder (root, 0);
   }

   private void debug_dump_inorder (bstree tree, int depth) {
      if (tree == null) return;
      debug_dump_inorder (tree.left, depth + 1);
      out.printf ("%*s%d: %s => %s%n",depth * 3, "", depth, tree.key, tree.value);
      debug_dump_inorder (tree.right, depth + 1);
   }

}
