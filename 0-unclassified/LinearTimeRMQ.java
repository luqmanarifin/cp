import java.util.*;
import java.io.*;
 
// current version doesn't work properly
 
public class LinearTimeRMQ
{
  // cartesian tree class declaration
  static class Node
  {
    public int key, priority;
    private Node left, right, parent;
    
    public Node(int key, int priority)
    {
      this.key = key;
      this.priority = priority;
    }
    
    public void setLeft(Node left)
    {
      assert left != this;
      this.left = left;
      if (left != null)
        left.parent = this;
    }
    
    public void setRight(Node right)
    {
      assert right != this;
      this.right = right;
      if (right != null)
        right.parent = this;
    }
  }
  
  // RMQ -> LCA reduction
  
  // linear-time construction of cartesian tree from integer array
  // keys are array indices, priorities are values
  static public Node buildTreeFromArray(int[] array)
  {
    int n = array.length;
    assert n > 0;
    
    Node tree = new Node(0, array[0]);
    for (int i = 1; i < n; i++)
    {
      Node node = new Node(i, array[i]);
      while (tree.parent != null && tree.priority > array[i])
      {
        tree = tree.parent;
      }
      
      if (tree.priority > array[i])
      {
        node.setLeft(tree);
      }
      else
      {
        node.setLeft(tree.right);
        tree.setRight(node);
      }
      tree = node;
    }
    while (tree.parent != null)
    {
      tree = tree.parent;
    }
    
    return tree;
  }
  
  // following procedure gives index -> node correspondence
  // for cartesian tree built by previous procedure
  static public void fillIndexToNode(Node[] array, Node node)
  {
    if (node == null)
      return;
    array[node.key] = node;
    fillIndexToNode(array, node.left);
    fillIndexToNode(array, node.right);
  }
  
  // LCA -> ±1 RMQ reduction
  static public int fillEulerWalk(int[] depths, int[] indices, int[] needValues, Node node, int start, int depth)
  {
    assert node != null;
    
    indices[node.key] = start;
    depths[start] = depth;
    needValues[start] = node.priority;
    if (node.left != null)
    {
      start = fillEulerWalk(depths, indices, needValues, node.left, start + 1, depth + 1);
      depths[start] = depth;
      needValues[start] = node.priority;
    }
    if (node.right != null)
    {
      start = fillEulerWalk(depths, indices, needValues, node.right, start + 1, depth + 1);
      depths[start] = depth;
      needValues[start] = node.priority;
    }
    return start + 1;
  }
  
  // sparse table construction
  // table[i][j] stores min(array[i; i + 2^j))
  static public int[][] buildSparseTable(int[] array)
  {
    int h = 0, s = 1;
    int n = array.length;
    while (s < array.length)
    {
      s *= 2;
      h++;
    }
    // h = ceil(log_2(n))
    
    int[][] result = new int[n][h + 1];
    for (int i = 0; i < n; i++)
      result[i][0] = array[i];
    
    s = 1;
    for (int j = 1; j <= h; j++)
    {
      for (int i = 0; i < n; i++)
      {
        result[i][j] = result[i][j - 1];
        if (i + s < n)
          result[i][j] = Math.min(result[i][j], result[i + s][j - 1]);
      }
      s *= 2;
    }
    
    return result;
  }
  
  // sparse table query
  // returns min(array[l; r))
  // logfloor and floorpow passed as parameters because it's computation
  // takes logarithmic time. Using precomputed values, we get constant
  // working time for query.
  static public int sparseTableQuery(int[][] table, int[] logfloor, int[] floorpow, int l, int r)
  {
    int h = logfloor[r - l];
    return Math.min(table[l][h], table[r - floorpow[r - l]][h]);
  }
  
  static public int[][][] build4RussiansTable(int n)
  {
    assert n > 0;
    int[][][] result = new int[1 << n][n][n + 1];
    for (int mask = 0; mask < (1 << (n - 1)); mask++)
    {
      int[] array = new int[n];
      array[0] = 0;
      for (int i = 1; i < n; i++)
      {
        array[i] = array[i - 1];
        if (((1 << (i - 1)) & mask) > 0)
          array[i] += 1;
        else
          array[i] -= 1;
      }
      for (int i = 0; i < n; i++)
        result[mask][i][i + 1] = array[i];
      for (int l = 2; l <= n; l++)
        for (int i = 0; i + l <= n; i++)
          result[mask][i][i + l] = Math.min(result[mask][i][i + l - 1], array[i + l - 1]);
    }
    return result;
  }
  
  int[] array; // done
  int[][] sparse; // done
  int[] logfloor; // done
  int[] floorpow; // done
  int blocksize; // done
  int[][][] rus4; // done
  int[] depths; // done
  int[] indices; // done
  Node tree;
  int[] blockmin;
  Node[] indexToNode;
  int[] needValues;
  
  public LinearTimeRMQ(int[] array)
  {
    this.array = array;
    tree = buildTreeFromArray(array);
    int n = array.length;
    depths = new int[2 * n - 1];
    needValues = new int[2 * n - 1];
    indices = new int[n];
    
    fillEulerWalk(depths, indices, needValues, tree, 0, 0);
    
    indexToNode = new Node[n];
    fillIndexToNode(indexToNode, tree);
    
    n = 2 * n - 1;
    int h = 0, s = 1;
    while (s < n)
    {
      h += 1;
      s *= 2;
    }
    blocksize = (h + 1) / 2;
    
    blockmin = new int[(n - 1) / blocksize + 1];
    for (int i = 0; i < n; i++)
    {
      //System.out.printf("i = %d, depths.length = %d\n", i, depths.length);
      int block = i / blocksize;
      if (i % blocksize == 0)
        blockmin[block] = depths[i];
      else
        blockmin[block] = Math.min(blockmin[block], depths[i]);
    }
    
    sparse = buildSparseTable(blockmin);
    
    int m = blockmin.length + 1;
    logfloor = new int[m];
    floorpow = new int[m];
    logfloor[1] = 0;
    floorpow[1] = 1;
    for (int i = 2; i < m; i++)
    {
      logfloor[i] = logfloor[i / 2] + 1;
      floorpow[i] = floorpow[i / 2] * 2;
    }
    
    rus4 = build4RussiansTable(blocksize);
  }
  
  public int getRMQ(int left, int right)
  {
    left = indices[left];
    right = indices[right - 1];
    
    if (right < left)
    {
      int temp = right;
      right = left;
      left = temp;
    }
    
    if (left == right)
    {
      return needValues[left];
    }
    
    //System.out.printf("left = %d, right = %d\n", left, right);
    
    int left_block = (left / blocksize);
    int right_block = (right / blocksize);
    
    int between_blocks = Integer.MAX_VALUE;
    if (left_block + 1 < right_block)
      between_blocks = sparseTableQuery(sparse, logfloor, floorpow, left_block + 1, right_block);
    
    int left_mask = 0;
    for (int k = 1; k < blocksize; k++)
      left_mask = left_mask * 2 + (depths[left_block * blocksize + k] - depths[left_block * blocksize + k - 1] + 1) / 2;
    int right_mask = 0;
    for (int k = 1; k < blocksize; k++)
      right_mask = right_mask * 2 + (depths[right_block * blocksize + k] - depths[right_block * blocksize + k - 1] + 1) / 2;
    
    int left_result = rus4[left_mask][left - left_block * blocksize][blocksize] + depths[left_block * blocksize];
    int right_result = rus4[right_mask][0][right - right_block * blocksize + 1] + depths[right_block * blocksize];
    
    //System.out.printf("%d, %d, %d\n", between_blocks, left_result, right_result);
    
    return needValues[Math.min(between_blocks, Math.min(left_result, right_result))];
  }
 
  public void testRMQ(int l, int r, PrintStream out)
  {
    int ans = array[l];
    for (int i = l + 1; i < r; i++)
    {
      ans = Math.min(ans, array[i]);
    }
    int result = getRMQ(l, r);
    
    if (ans == result)
      out.printf("ok, rmq(%d, %d) = %d\n", l, r, ans);
    else
      out.printf("wa, rmq(%d, %d) = %d, expected %d\n", l, r, result, ans);
  }
  
  // debug output: print tree to stream
  static void printTree(Node tree, String spaces, PrintStream stream)
  {
    if (tree == null)
      return;
    stream.print(spaces);
    stream.printf("%d, %d\n", tree.key, tree.priority);
    printTree(tree.left, spaces + "   ", stream);
    printTree(tree.right, spaces + "   ", stream);
  }
  
  public static void main(String[] args) throws IOException
  {
    int[] array = new int[] { 4, 2, 1, 5, 7, 9, -1, -3 };
    int n = array.length;
    
    Node tree = buildTreeFromArray(array);
    Node[] indexToNode = new Node[n];
    fillIndexToNode(indexToNode, tree);
    
    printTree(tree, "", System.out);
    
    System.out.println(Arrays.toString(array));
    
    LinearTimeRMQ rmq = new LinearTimeRMQ(array);
    
    System.out.println(rmq.blocksize);
    System.out.println(Arrays.toString(rmq.blockmin));
    System.out.println(Arrays.toString(rmq.depths));
    System.out.println();
    for (int[] row : rmq.sparse)
    {
      System.out.println(Arrays.toString(row));
    }
    System.out.println();
    
    for (int[][] row : rmq.rus4)
    {
      System.out.println(Arrays.deepToString(row));
    }
    
    for (int i = 0; i < n; i++)
    {
      for (int j = i + 1; j < n; j++)
      {
        rmq.testRMQ(i, j, System.out);
      }
    }
    
    return;
  }
  
}

