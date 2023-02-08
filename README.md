<div align="center">
<br>
<img src="https://i.postimg.cc/XNDdMCcQ/documentation-icon.png" width="90">
<h3>RANDOM - STRING - GENERATOR</h3>
<p>[ c++ implementation using TinyMT32 algorithm ]</p>
<a href="https://www.rfc-editor.org/rfc/rfc8682.pdf" targer="_blank"><i>Read more about TinyMT32 PRNG</i></a>
<br><br>
</div>

### Table of contents

- [[1] Disclaimer](#disclaimer)
- [[2] Performance](#performance)
- [[3] External links](#external-links)

<!--DISCLAIMER SECTION-->
<br>
<h3 name="disclaimer">Disclaimer</h3>

---

> :warning: This algorithm **ISN'T** designed for production use. It was created for educational purpose.

> :bulb: TinyMT32 algorithm was developed by <i>M. Saito, M. Matsumoto, V. Roca, Ed. and E. Baccelli</i>. [[RFC8682](https://www.rfc-editor.org/rfc/rfc8682.pdf)]

<!--PERFORMANCE SECTION-->
<br>
<h3 name="performance">Performance</h3>

---
<br>

| No. of strings | No. of characters | Run time |
| :------------: | :---------------: | :------: |
| 1              | 100               | ~31 microseconds |
| 1              | 100.000           | ~15.000 microseconds |
| 100.000        | 100               | ~1 seconds |
| 1.000.000      | 100               | ~14 seconds |

<!--EXTERNAL LINKS SECTION-->
<br>
<h3 name="external-links">External links</h3>

---

- [[RFC8682] TinyMT32 Pseudorandom Number Generator (PRNG)](https://www.rfc-editor.org/rfc/rfc8682.pdf)
- [Random Number Generator Results (CAcert)](http://www.cacert.at/cgi-bin/rngresults)
