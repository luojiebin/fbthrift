from libcpp.string cimport string
from libcpp.memory cimport shared_ptr
from libc.stdint cimport uint64_t, uint32_t, uint16_t
from folly cimport cFollyFuture
from thrift.py3.client cimport cRequestChannel_ptr


cdef extern from "folly/ssl/Init.h" namespace "folly::ssl" nogil:
    void init()


cdef extern from "folly/io/async/SSLContext.h":
    cdef cppclass cSSLVersion "folly::SSLContext::SSLVersion":
        bint operator==(cSSLVersion&)

    cSSLVersion cTLSv1_2 "folly::SSLContext::TLSv1_2"

    cdef cppclass cSSLVerifyPeerEnum "folly::SSLContext::SSLVerifyPeerEnum":
        bint operator==(cSSLVerifyPeerEnum&)

    cSSLVerifyPeerEnum cVERIFY_REQ_CLIENT_CERT "folly::SSLContext::VERIFY_REQ_CLIENT_CERT"
    cSSLVerifyPeerEnum cVERIFY "folly::SSLContext::VERIFY"
    cSSLVerifyPeerEnum cNO_VERIFY "folly::SSLContext::NO_VERIFY"

    cdef cppclass cSSLContext "folly::SSLContext" nogil:
        cSSLContext(cSSLVersion version)
        void setVerificationOption(const cSSLVerifyPeerEnum& verify)
        bint needsPeerVerification()
        void loadCertKeyPairFromFiles(const char* certPath, const char* keyPath) except+
        void loadTrustedCertificates(const char* path) except+
        void authenticate(bint checkPeerCert, bint checkPeerName)


cdef extern from "<utility>" namespace "std" nogil:
    cdef shared_ptr[cSSLContext] move(shared_ptr[cSSLContext])


cdef extern from "thrift/lib/py3/ssl.h" namespace "thrift::py3":
    cdef cFollyFuture[cRequestChannel_ptr] createThriftChannelTCP(
        shared_ptr[cSSLContext]& ctx,
        cFollyFuture[string] fut,
        const uint16_t port,
        const uint32_t connect_timeout,
        const uint32_t ssl_timeout,
    )


cdef class SSLContext:
    cdef object __weakref__
    cdef shared_ptr[cSSLContext] _cpp_obj
