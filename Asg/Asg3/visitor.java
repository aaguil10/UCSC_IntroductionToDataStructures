// $Id: visitor.java,v 1.1 2012-10-31 13:12:50-07 - - $
// Alejandro Aguilar aaguil10@ucsc.edu

interface visitor <key_t, value_t> {
   public void visit (key_t key, value_t value);
}
