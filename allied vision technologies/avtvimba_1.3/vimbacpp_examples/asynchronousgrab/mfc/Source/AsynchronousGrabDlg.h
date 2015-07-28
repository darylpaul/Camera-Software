/*=============================================================================
  Copyright (C) 2012 Allied Vision Technologies.  All Rights Reserved.

  Redistribution of this file, in original or modified form, without
  prior written consent of Allied Vision Technologies is prohibited.

-------------------------------------------------------------------------------

  File:        AsynchronousGrabDlg.h

  Description: MFC dialog class for the GUI of the AsynchronousGrab example of
               VimbaCPP.

-------------------------------------------------------------------------------

  THIS SOFTWARE IS PROVIDED BY THE AUTHOR "AS IS" AND ANY EXPRESS OR IMPLIED
  WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF TITLE,
  NON-INFRINGEMENT, MERCHANTABILITY AND FITNESS FOR A PARTICULAR  PURPOSE ARE
  DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,
  INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
  (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
  AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR
  TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

=============================================================================*/

#pragma once

#include <vector>
#include <afxwin.h>
#include <atlimage.h>

#include <VimbaCPP/Include/VimbaCPP.h>

#include <ApiController.h>

using namespace AVT::VmbAPI;
using namespace AVT::VmbAPI::Examples;

class CAsynchronousGrabDlg : public CDialog
{
public:
    CAsynchronousGrabDlg( CWnd* pParent = NULL );

    enum { IDD = IDD_ASYNCHRONOUSGRAB_DIALOG };

protected:
    virtual void DoDataExchange( CDataExchange* pDX );

protected:
    HICON m_hIcon;

    virtual BOOL OnInitDialog();
    afx_msg void OnSysCommand( UINT nID, LPARAM lParam );
    afx_msg void OnPaint();
    afx_msg HCURSOR OnQueryDragIcon();
    afx_msg void OnBnClickedButtonStartstop();
    DECLARE_MESSAGE_MAP()

    // The event handler for the frame received event
    afx_msg LRESULT OnFrameReady( WPARAM status, LPARAM lParam );
    // The event handler for the camera list changed event
    afx_msg LRESULT OnCameraListChanged( WPARAM reason, LPARAM lParam );

private:
    // Our controller that wraps API access
    ApiController m_ApiController;
    // A list of known camera IDs
    std::vector<std::string> m_cameras;
    // Are we streaming?
    bool m_bIsStreaming;
    // Our MFC image to display
    CImage m_Image;

    // Queries and lists all known camera
    void UpdateCameraListBox();
    // Prints out some logging
    void Log( string_type strMsg, VmbErrorType eErr );
    // Copies the content of a byte buffer to a MFC image
    void CopyToImage( VmbUchar_t *pInBuffer, VmbPixelFormat_t PixelFormat, CImage &pOutImage );

    // MFC Controls
    CListBox m_ListBoxCameras;
    CListBox m_ListLog;
    CButton m_ButtonStartStop;
    CStatic m_PictureBoxStream;
};

