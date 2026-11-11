# Code style

## Files

- Procedures of a source file are defined in the order of their addresses:
  the compiler places the procedures of a file in the order of their
  definitions.
- Each procedure starts with a metadata comment, separated from the
  definition by a blank line. A procedure of several modules lists each
  module with its address:

  ```cpp
  /*
  * Module:                 rOpenGL.dll
  * Entry point:            0x1000354D
  * Module:                 Blade.exe
  * Entry point:            0x00404CFD
  * VC++ mangling:          ??0B_Matrix@@QAE@N@Z
  */

  B_Matrix::B_Matrix(double scale)
  {
      ...
  }
  ```

- Procedures are separated by two blank lines.
- Unknown code between two procedures (procedures which are not
  reconstructed and not declared yet) is marked by a block of dots:

  ```cpp
  /*
  ................................................................................
  ................................................................................
  ................................................................................
  ................................................................................
  */
  ```

- A declared but not reconstructed procedure is a stub excluded from the
  native build:

  ```cpp
  #ifndef BLD_NATIVE
  unsigned int B_BoundingBox::Intersects(const B_Sector *sector) const
  {
      return 0;
  }
  #endif
  ```

- A procedure is defined in the source file of its module in the binary:
  the code of a source file is contiguous, so a procedure placed between
  procedures of `OctTree.cpp` belongs to `OctTree.cpp` even if it is a
  method of another class (`B_BoundingBox::CollectIntersectingSectors`).
- Lines don't have trailing spaces, a file ends with a newline.

## Layout

- Indentation is 4 spaces.
- Opening braces are on separate lines.
- There is no `;` after the closing brace of a function.
- Bodies of `if`, `else`, `for` and `while` are always in braces, also a
  single statement:

  ```cpp
  if (map.size == 0)
  {
      return nullptr;
  }
  for (unsigned int i = 0; i < map.size; i++)
  {
      sectorList->Append(map[i]);
  }
  ```

- There are no blank lines inside procedures, including empty bodies and
  lines before `return`:

  ```cpp
  LeafNode::~LeafNode()
  {
  }
  ```

- `&` and `*` are attached to names, not to types:
  `const B_Vector &that`, `B_Sector *sector`,
  `B_IDataFile &operator >>(B_IDataFile &file, B_Matrix &matrix)`.
- Initializer lists start with `:` on a separate line, each initializer is
  on its own line:

  ```cpp
  B_BoundingBox::B_BoundingBox(
      const B_Vector &minCoords,
      const B_Vector &maxCoords
  )
  :
      minCoords(minCoords),
      maxCoords(maxCoords)
  {
  }
  ```

## Long lines

Lines are not longer than 80 characters. Long lines are wrapped this way:

- Parameters of a definition are on separate lines, `)` is on its own line:

  ```cpp
  void B_OctantNode::CollectSectorsInBox(
      const B_BoundingBox &bb,
      B_OctTreeSectorsList *outList,
      double halfSize
  )
  ```

- A long condition is between `(` and `)` on their own lines, it is broken
  after `&&` and `||`:

  ```cpp
  if (
      this->elements[i]->lastQueryId != gbl_oct_tree_query_id &&
      this->elements[i]->isActive != 0
  )
  ```

- A long assignment is broken after `=`, the value is indented:

  ```cpp
  octantNode->children[0] =
      BuildNode(outBuffer, sizeThreshold, childBoundingBox);
  ```

- A long binary expression has an operand on each line, the operator is at
  the end of the line, continuation lines are indented once more:

  ```cpp
  out.x =
      v.x * matrix.m[0][0] +
          v.y * matrix.m[1][0] +
          v.z * matrix.m[2][0] +
          matrix.m[3][0];
  ```

- Arguments of a long call are on separate lines, `)` or `);` is on its own
  line:

  ```cpp
  this->children[0]->CollectSectorsInBox(
      childBoundingBox,
      outList,
      childHalfSize
  );
  ```

## Expressions

- Fields and methods of the object are accessed with explicit `this->`:
  `this->children[i] = nullptr;`.
- Pointers are compared with `nullptr` explicitly:
  `this->children[0] != nullptr`, not `this->children[0]`.
- Floating point literals have a fractional part: `0.0`, `1.0`, `0.5f`.
- Loop counters are incremented with postfix `i++`.
- Nested `if` statements without `else` are merged with `&&`:
  `if (bb.minCoords.z < 10.0 && this->children[0] != nullptr)`.
