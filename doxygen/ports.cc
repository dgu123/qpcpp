namespace QP {

/*! @page ports Ports

@section ports_gen General Comments
The QP/C framework can be easily adapted to various operating systems, processor architectures, and compilers. Adapting the QP/C software is called porting and the QP/C framework has been designed from the ground up to make porting easy.

The QP/C distribution contains many QP/C ports, which are organized into the three categories:

- @subpage ports_native "Native Ports" adapt QP/C to run on bare-metal processors "natively", using one of the built-in kernels (@ref comp_qv "QV" or @ref comp_qk "QK")

- @subpage ports_rtos "3rd-Party RTOS Ports" adapt QP/C to run on top of a 3rd-Party Real-Time Operating System (RTOS)

- @subpage ports_os "3rd-Party OS Ports" adapt QP/C to run on top of a 3rd-Party Operating System (OS), such as Windows or Linux.


------------------------------------------------------------------------------
@section ports_code Port Code Structure
Starting with QP/C release 5.4.0, **all** available ports are bundled into the QP/C download, as opposed to being distributed as separate QP Development Kits (QDKs). The main benefit is of this approach is that it greatly reduces chances of mistakes in combining the mainline QP/C code with various QDKs. The downside is that the QP/C distribution becomes quite large and that ports cannot be added or updated independently from the QP/C baseline code.

All ports are located in sub-directories of the <span class="img folder">ports</span> @ref qpc_files "top-level folder", with the hierarchical organization outlined below:

<ul class="tag">
  <li><span class="img folder">ports</span>
  </li>
  <ul class="tag">
    <li><span class="img folder">arm-cm</span> &mdash; Native ports for ARM-Cortex-M (bare-metal) <span class="tag">A</span>
    </li>
    <ul class="tag">
      <li><span class="img folder">qk</span> &mdash; Port to the @ref comp_qk "preemptive QK kernel" 
      </li>
      <ul class="tag">
        <li><span class="img folder">arm</span> &mdash; Port to ARM-KEIL toolset
        </li>
        <ul class="tag">
          <li><span class="img folder">dbg</span> &mdash; Debug @ref exa_sec_conf "build configuration"
          </li>
          <li><span class="img folder">rel</span> &mdash; Release build configuration
          </li>
          <li><span class="img folder">spy</span> &mdash; Spy build configuration
          </li>
        </ul>  
        <li><span class="img folder">gnu</span> &mdash; Port to GNU toolset
        </li>
        <li><span class="img folder">iar</span> &mdash; Port to IAR toolset
        </li>
      </ul>  
    </ul>  
    <ul class="tag">
      <li><span class="img folder">qk</span> &mdash; Port to the @ref comp_qv "cooperative QV kernel" 
      </li>
      <ul class="tag">
        <li><span class="img folder">arm</span> &mdash; Port to ARM-KEIL toolset
        </li>
        <ul class="tag">
          <li><span class="img folder">dbg</span> &mdash; Debug @ref exa_sec_conf "build configuration"
          </li>
          <li><span class="img folder">rel</span> &mdash; Release build configuration
          </li>
          <li><span class="img folder">spy</span> &mdash; Spy build configuration
          </li>
        </ul>  
        <li><span class="img folder">gnu</span> &mdash; Port to GNU toolset
        </li>
        <li><span class="img folder">iar</span> &mdash; Port to IAR toolset
        </li>
      </ul>  
    </ul>  

    <li><span class="img folder">ucos-ii</span> &mdash; Port to uCOS-II (3rd-party RTOS) <span class="tag">B</span>
    </li>  
    <ul class="tag">
      <li><span class="img folder">arm-cm</span> &mdash; Port to ARM-Cortex-M
      </li>
      <ul class="tag">
        <li><span class="img folder">arm</span> &mdash; build with ARM toolset
        </li>
        <ul class="tag">
          <li><span class="img folder">dbg</span> &mdash; Debug build configuration
          </li>
          <li><span class="img folder">rel</span> &mdash; Release build configuration
          </li>
          <li><span class="img folder">spy</span> &mdash; Spy build configuration
          </li>
        </ul>  
        <li><span class="img folder">iar</span> &mdash; build with IAR toolset
        </li>
      </ul>
    </ul>  

    <li><span class="img folder">win32</span> &mdash; Port to Win32 (Windows) <span class="tag">C</span>
    </li>  
    <ul class="tag">
      <li><span class="img folder">mingw</span> &mdash; build with MinGW (GNU) toolset
      </li>
      <ul class="tag">
        <li><span class="img folder">dbg</span> &mdash; Debug build configuration
        </li>
        <li><span class="img folder">rel</span> &mdash; Release build configuration
        </li>
        <li><span class="img folder">spy</span> &mdash; Spy build configuration
        </li>
      </ul>  
      <li><span class="img folder">vc</span> &mdash; build with Visual C++ toolset
      </li>
      <ul class="tag">
        <li><span class="img folder">Debug</span> &mdash; Debug build configuration
        </li>
        <li><span class="img folder">Release</span> &mdash; Release build configuration
        </li>
        <li><span class="img folder">QSpy</span> &mdash; Spy build configuration
        </li>
      </ul>  
    </ul>
  </ul>  
</ul>    

<ul class="tag">
  <li><span class="tag">A</span> **Native Ports** are located in sub-directories named after the CPU architecture, such as <span class="img folder">arm-cm</span> for ARM Cortex-M. Under that directory, the sub-directories <span class="img folder">qk</span> and <span class="img folder">qv</span> contain ports for the @ref comp_qk "QK" and @ref comp_qv "QV" kernels, respectively.
  </li>
  
  <li><span class="tag">B</span> **Ports for 3rd-party RTOS** are located in sub-directories named after the RTOS, such as <span class="img folder">ucos-ii</span> for uCOS-II RTOS. Under that directory, the sub-directories, such as <span class="img folder">arm-cm</span>, contain examples for the specified CPU architecture, such as ARM Cortex-M here.
  </li>

  <li><span class="tag">C</span> **Ports for 3rd-party OS** are located in sub-directories named after the OS, such as <span class="img folder">win32</span> for the Win32 API (Windows OS). Under that directory, the sub-directories, such as <span class="img folder">mingw</span>, contain builds for the specified toolset, such as MinGW or Visual C++ here.
  </li>
</ul>

@note
Because the QP distribution contains *all* ports, the number of sub-directories and files in the <span class="img folder">ports</span> folder may seem daunting. However, knowing the structure of the <span class="img folder">ports</span> folder, you can simply **delete** the sub-directories that are not interesting to you. 


@next{ports_native}
*/

} // namespace QP
